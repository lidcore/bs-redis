open BsAsyncMonad;
open BsAsyncMonad.Callback;

open Tape;

test("get/set", t => {
  t.plan(1);
  let client = Redis.init();
  Callback.finish(
    Redis.set(client, "ping", "pong")
    >> (
      _ =>
        Redis.get(client, "ping")
        >> (
          res =>
            Redis.quit(client)
            >> (
              _ => {
                t.equalStr(res, "pong");
                Callback.return();
              }
            )
        )
    ),
  );
});

test("setnx sanity check", t => {
  t.plan(1);
  let client = Redis.init();
  Callback.finish(
    Redis.setnx(client, "pingnx", "pong")
    >> (
      _ =>
        Redis.get(client, "pingnx")
        >> (
          res =>
            Redis.quit(client)
            >> (
              _ => {
                t.equalStr(res, "pong");
                Callback.return();
              }
            )
        )
    ),
  );
});
