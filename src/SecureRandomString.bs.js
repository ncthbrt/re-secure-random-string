// Generated by BUCKLESCRIPT VERSION 3.1.0, PLEASE EDIT WITH CARE
'use strict';

var Js_exn = require("bs-platform/lib/js/js_exn.js");
var SecureRandomString = require("secure-random-string");

function gen($staropt$star, $staropt$star$1, _) {
  var length = $staropt$star ? $staropt$star[0] : 32;
  var alphaNumeric = $staropt$star$1 ? $staropt$star$1[0] : false;
  return new Promise((function (resolve, reject) {
                try {
                  SecureRandomString({
                        length: length,
                        alphanumeric: alphaNumeric
                      }, (function (err, result) {
                          if (err == null) {
                            return resolve(result);
                          } else {
                            return reject(err);
                          }
                        }));
                  return /* () */0;
                }
                catch (raw_err){
                  var err = Js_exn.internalToOCamlException(raw_err);
                  return reject(err);
                }
              }));
}

function genSync($staropt$star, $staropt$star$1, _) {
  var length = $staropt$star ? $staropt$star[0] : 32;
  var alphaNumeric = $staropt$star$1 ? $staropt$star$1[0] : false;
  return SecureRandomString({
              length: length,
              alphanumeric: alphaNumeric
            });
}

exports.gen = gen;
exports.genSync = genSync;
/* secure-random-string Not a pure module */
