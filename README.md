# C Library - Russell's personal C standard library

## WARNING

While this project is MIT Licensed, I do not recommend using it.
The APIs are unstable and incomplete, and I do not plan on marking them
stable until I am 100% happy with them.

## About the Project

Are you writing C but you're tired of implementing linked lists?
Don't want to use C++ templates or crazy C macros for generic data structures?
Just generate them! Easy generic data structures without the mess!

## How to Run

Run:
```bash
$ ./build.sh
```

Then run:
```bash
$ ./generate --help
```
to print the help info.

## How to Run Tests

```
./test.sh
```

## This Project's Vision

I'm working towards a general C library that I can use in 3 projects:
- advent of code 2025
- a REST web server
- a desktop application

The first one is the proving ground for the next two. 

Here's how I envision the web server working.

// todo_controller.c
```c
typedef struct {
  Headers headers;
  Params params;
  String body;
} Request;

typedef struct {
  u16 code;
  Headers headers;
  Params params;
  String body;
} Response;

Response getTodos(Request req, Response resp) {
  Arena a;
  Result create_arena_result = create_arena(&a, KiB(4));
  if (create_arena_result.status != SUCCESS) {
    resp.code = 500;
    return resp;
  }

  DBResponse todos = db_get_todos();
  if (todos.status != SUCCESS) {
    free_arena(&a);
    resp.code = 500;
    return resp;
  }

  resp.body = json_serialize(todos);
  free_arena(&a);
  resp.code = 200;
  return resp;
}

```

// router.c
```c
#include "./controllers/todo_controller.h"

// TODO: proper syntax here
Route[] routes() {
  Route r[2];
  r[0] = { GET, "/api/v1/todo", (*getTodos)(Request, Response) }
  r[1] = { POST, "/api/v1/todo", (*createTodo)(Request, Response) }
}
