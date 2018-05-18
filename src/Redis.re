type t;

external empty : unit => t = "%identity";

[@bs.module "redis"] [@bs.new] external init : unit => t = "createClient";

[@bs.send]
external set : (t, string, string, BsCallback.callback(string)) => unit = "";

[@bs.send]
external get : (t, string, BsCallback.callback(string)) => unit = "";

[@bs.send] external quit : (t, BsCallback.callback(string)) => unit = "";

[@bs.send]
external brpop :
  (t, string, int, BsCallback.callback((string, string))) => unit =
  "";
