#! /bin/bash

# This script exports the env variable MASSCALCULATOR_SOURCE, pointing at the 
# root directory of the MassCalculator core library codebase.

# Check if this file has been sourced of executed.
# $BASH_SOURCE is always this file, whether "sourced" or executed.
# $0 is the executing process ("bash" when sourced, this file when executed).
if [[ "$0" == "${BASH_SOURCE}" ]]; then
  {
    echo "This file is meant to be 'sourced', not executed:"
    echo
    echo " source "$0""
  } >&2
exit 1
fi

# No matter from where this script is called, obtain the MASSCALCULATOR root dir.
MASSCALCULATOR_SOURCE="$(dirname "$(dirname "$(realpath "${BASH_SOURCE}")")")" > /dev/null
export MASSCALCULATOR_SOURCE
