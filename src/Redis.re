open BsAsyncMonad;

type t;

external empty : unit => t = "%identity";

[@bs.module "redis"] [@bs.new] external init : unit => t = "createClient";

[@bs.send]
external brpop :
  (t, string, int, Callback.callback((string, string))) => unit =
  "";

[@bs.send]
external expire : (t, string, float, Callback.callback(unit)) => unit = "";

[@bs.send] external get : (t, string, Callback.callback(string)) => unit = "";

[@bs.send]
external set : (t, string, string, Callback.callback(string)) => unit = "";

[@bs.send]
external setnx : (t, string, string, Callback.callback(int)) => unit = "";

[@bs.send] external quit : (t, Callback.callback(string)) => unit = "";
