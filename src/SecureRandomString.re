type srsArgs = {. "length": int, "alphanumeric": Js.boolean };

[@bs.module]
external srs_: (srsArgs, ((Js.nullable(exn), string) => unit)) => unit = "secure-random-string";
[@bs.module]
external srsSync_: (srsArgs) => string =  "secure-random-string";

let gen = (~length=32, ~alphaNumeric=false, ()) => 
  Js.Promise.make((~resolve, ~reject) => {
    try (
      srs_(
        { "length": length, "alphanumeric": Js.Boolean.to_js_boolean(alphaNumeric) }, 
        (err, result) => 
          switch (err |> Js.Nullable.to_opt) {
            | Some(e) => [@bs] reject(e)
            | None => [@bs] resolve(result: string)
          }     
      )
    ) { | err => [@bs] reject(err) }
  });

let genSync = (~length=32, ~alphaNumeric=false, ()) =>  srsSync_({"length": length, "alphanumeric": Js.Boolean.to_js_boolean(alphaNumeric) });

