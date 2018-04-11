type srsArgs = {
  .
  "length": int,
  "alphanumeric": Js.boolean,
};

[@bs.module]
external srs_ : (srsArgs, (Js.nullable(exn), string) => unit) => unit =
  "secure-random-string";

[@bs.module] external srsSync_ : srsArgs => string = "secure-random-string";

let gen = (~length=32, ~alphaNumeric=false, ()) =>
  Js.Promise.make((~resolve, ~reject) =>
    try (
      srs_(
        {
          "length": length,
          "alphanumeric": Js.Boolean.to_js_boolean(alphaNumeric),
        },
        (err, result) =>
        switch (err |> Js.Nullable.toOption) {
        | Some(e) => reject(. e)
        | None => resolve(. result: string)
        }
      )
    ) {
    | err => reject(. err)
    }
  );

let genSync = (~length=32, ~alphaNumeric=false, ()) =>
  srsSync_({
    "length": length,
    "alphanumeric": Js.Boolean.to_js_boolean(alphaNumeric),
  });