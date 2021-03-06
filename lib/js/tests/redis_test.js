// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var Tape = require("bs-tape/lib/js/src/Tape.bs.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Redis = require("redis");
var BsAsyncMonad = require("bs-async-monad/lib/js/src/bsAsyncMonad.js");

Tape.test("get/set", (function (t) {
        Curry._1(t[/* plan */0], 1);
        var client = new Redis.createClient();
        return BsAsyncMonad.Callback[/* finish */26](/* None */0, BsAsyncMonad.Callback[/* >> */5]((function (param) {
                          client.set("ping", "pong", param);
                          return /* () */0;
                        }), (function () {
                          return BsAsyncMonad.Callback[/* >> */5]((function (param) {
                                        client.get("ping", param);
                                        return /* () */0;
                                      }), (function (res) {
                                        return BsAsyncMonad.Callback[/* >> */5]((function (param) {
                                                      client.quit(param);
                                                      return /* () */0;
                                                    }), (function () {
                                                      Curry._3(t[/* equalStr */10], /* None */0, res, "pong");
                                                      var partial_arg = BsAsyncMonad.Callback[/* return */2];
                                                      return (function (param) {
                                                          return partial_arg(/* () */0, param);
                                                        });
                                                    }));
                                      }));
                        })));
      }));

Tape.test("setnx sanity check", (function (t) {
        Curry._1(t[/* plan */0], 1);
        var client = new Redis.createClient();
        return BsAsyncMonad.Callback[/* finish */26](/* None */0, BsAsyncMonad.Callback[/* >> */5]((function (param) {
                          client.setnx("pingnx", "pong", param);
                          return /* () */0;
                        }), (function () {
                          return BsAsyncMonad.Callback[/* >> */5]((function (param) {
                                        client.get("pingnx", param);
                                        return /* () */0;
                                      }), (function (res) {
                                        return BsAsyncMonad.Callback[/* >> */5]((function (param) {
                                                      client.quit(param);
                                                      return /* () */0;
                                                    }), (function () {
                                                      Curry._3(t[/* equalStr */10], /* None */0, res, "pong");
                                                      var partial_arg = BsAsyncMonad.Callback[/* return */2];
                                                      return (function (param) {
                                                          return partial_arg(/* () */0, param);
                                                        });
                                                    }));
                                      }));
                        })));
      }));

/*  Not a pure module */
