#!/bin/bash
set -e

cd wk-svn

git add -A
git diff master > ../wk.patch