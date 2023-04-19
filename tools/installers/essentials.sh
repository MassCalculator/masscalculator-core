#!/bin/bash
CURRENT_DIRECTORY="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# If OUTPUT has not been defined earlier, set it to /dev/null
OUTPUT=${OUTPUT-/dev/null}

echo "[INFO] Performing system-run to wait for any \"apt\" processes to complete. This may take several minutes."
systemd-run --property="After=apt-daily.service apt-daily-upgrade.service" --wait /bin/true &>/dev/null

echo "[INFO] Initializing..."
apt-get update > ${OUTPUT} 2>&1

[[ ! -e ${CURRENT_DIRECTORY}/common.sh ]] && \
echo "This script requires ${CURRENT_DIRECTORY}/common.sh to run." && exit 1
source ${CURRENT_DIRECTORY}/common.sh

# @todo(jimmyhalimi): Update the list with packages.
echo "[INFO] Installing required packages from apt..."
apt-get install -y --no-install-recommends \
apt-utils \
build-essential \
clang-format-13 \
clang-tidy-13 \
clang-13 \
ccache \
curl \
cmake \
graphviz \
doxygen \
git \
libgtest-dev \
libdxflib-dev \
liblua5.1-0-dev \
ninja-build \
software-properties-common \
sudo \
unzip \
vim \
wget > ${OUTPUT} 2>&1 && rc=$? || rc=$?
[[ $rc -ne 0 ]] && on_exit $rc

echo "[INFO] Installing required packages from pip..."
pip install cpplint pylint conan > ${OUTPUT} 2>&1 && rc=$? || rc=$?
[[ $rc -ne 0 ]] && on_exit $rc

# Conan configuration
echo "[INFO] Configuring default conan profile..."
conan profile detect

on_exit 0
