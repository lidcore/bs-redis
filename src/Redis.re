open BsAsyncMonad;
open BsAsyncMonad.Callback;

type t;

external empty : unit => t = "%identity";

[@bs.module "redis"] [@bs.new] external init : unit => t = "createClient";

[@bs.send]
external set : (t, string, string, Callback.callback(string)) => unit = "";

[@bs.send] external get : (t, string, Callback.callback(string)) => unit = "";

[@bs.send] external quit : (t, Callback.callback(string)) => unit = "";

[@bs.send]
external brpop :
  (t, string, int, Callback.callback((string, string))) => unit =
  "";
