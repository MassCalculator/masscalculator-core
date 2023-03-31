# Environmental Variables

## MASSCALCULATOR_SOURCE

An environment variable `MASSCALCULATOR_SOURCE` is defined to point at the root directory
of the codebase. To set it, run from the repository root.

```bash
source tools/envsetup.sh
```

Developers should add this command (pointing at the `.sh` file in your
filesystem) to their user `~/.bashrc` (or equivalent) file to automatically
run it at every shell instantiation.

## MASSCALCULATOR_HOME

`MASSCALCULATOR_HOME` is a CMake variable that you will see often around the
codebase and the documentation. By default the location is:

```bash
~/.masscalculator
```

That is, a folder called `.masscalculator` under the Linux user home.
