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
