#!/bin/bash
APP_NAME="TodoC"
VERSION="1.0"
OUTPUT_DIR="build/bin"
ZIP_NAME="${APP_NAME}_${VERSION}_linux.zip"

cd "$OUTPUT_DIR" || exit
zip -r "../../${ZIP_NAME}" *
echo "Packaged: ${ZIP_NAME}"

