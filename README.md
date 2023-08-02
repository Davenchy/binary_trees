# Binary Trees

## Build

- To build and run task

```bash
$ make run task=0
```

- To rebuild and run task

```bash
$ make rerun task=0
```

- You can add extra c files to the build
- Let's say you want to build a task that has a dependency from previous tasks
- The dependency files name are `0-binary_tree_node.c`, `1-binary_tree_insert_left.c`, `2-binary_tree_insert_right.c`

```bash
$ make run task=16 extra="binary_tree_node binary_tree_insert*"
# OR
$ make rerun task=16 extra="binary_tree_node" files="*-binary_tree_insert*.c"
```

- The `extra` variable is the same as the `files` variable the only deference is
that the `extra` variable adds `*-` before the **wildcard** and `.c` after it.

### Make Targets

- `build`: builds the task chosen by the `TASK` variable with `EXTRA`
- `run`: executes the executable and if not exists runs the `build` target
- `rerun`: runs `fclean` then `run`
- `betty`: executes the `betty` command to check all source code
- `clean`: removes all object files
- `fclean`: removes all object files and the executable
