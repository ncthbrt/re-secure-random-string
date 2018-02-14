open Jest;

open Js.Promise;
open SecureRandomString;
open ExpectJs;

let (>>) = (f, g, x) => x |> f |> g;

let map = (f, p) => then_(f >> resolve, p);

let toBeAlphaNumeric = (~length=32) => toMatchRe(Js.Re.fromString({j|[A-Za-z0-9]{$length}|j}));

let toBeRejected = (`Just(v)) =>  {  
  v 
  |> Js.Promise.then_((_) => Js.Promise.resolve(fail("Promise should've been rejected")))
  |> Js.Promise.catch((_) => resolve(pass));
};

describe("gen", () => {
  testPromise(
    "should be able to be invoked with default arguments", 
    () => gen() |> map (String.length >> expect >> toEqual(32))
  );
  testPromise(
    "should be able to be invoked with custom length", 
    () => gen(~length=64, ()) |> map(String.length >> expect >> toEqual(64))
  );
  testPromise(
    "should be able to be invoked with alphanumericity", 
    () => gen(~alphaNumeric=true, ()) |> map (expect >> toBeAlphaNumeric)
  );   
  testPromise(
    "should reject on invalid length",
    () => expect(gen(~length=-64, ())) |> toBeRejected
  );   
});

describe("genSync", () => {
  test(
    "should be able to be invoked with default arguments", 
    () => expect(genSync() |> String.length) |> toEqual(32) 
  );  
  test(
    "should be able to be invoked with custom length", 
    () => expect(genSync(~length=64, ()) |> String.length) |> toEqual(64)
  );
  test(
    "should be able to be invoked with alphanumericity", 
    () => expect(genSync(~alphaNumeric=true, ())) |> toBeAlphaNumeric 
  );
});