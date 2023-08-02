# Binary Trees

## Build

- To build and run task

```bash
$ make run TASK=0
```

- To rebuild and run task

```bash
$ make rerun TASK=0
```

- You can add extra c files to the build
- Let's say you want to build a task that has a dependency from previous tasks
- The dependency file name is `0-binary_tree_node.c`

```bash
$ make run TASK=1 EXTRA="binary_tree_node"
```

### Make Targets

- `build`: builds the task chosen by the `TASK` variable with `EXTRA`
- `run`: executes the executable and if not exists runs the `build` target
- `rerun`: runs `fclean` then `run`
- `betty`: executes the `betty` command to check all source code
- `clean`: removes all object files
- `fclean`: removes all object files and the executable
