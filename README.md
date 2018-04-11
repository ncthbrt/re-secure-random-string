# re-secure-random-string
This is a simple wrapper around node's `secure-random-string` for BuckleScript and Reason. Safely generating a random string for cryptographic purposes is difficult using Node's build in crypto library. The `secure-random-string` library aims to make this easier.

## Getting Started

Install using npm:
```
npm install --save @ncthbrt/re-secure-random-string
```
Then add `@ncthbrt/re-secure-random-string` as a dependency in `bsconfig.json`.

## Usage
### Synchronous usage
```reason
let randomString = SecureRandomString.gen(~length=64, ());
```
### Asynchronous usage
```reason
SecureRandomString.gen(~length=64, ())
|> Js.Promise.then_(randomString => {
      Js.log2("Random string is", randomString);
      Js.Promise.resolve();
});
```
