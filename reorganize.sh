#!/bin/bash
# Run this INSIDE your local clone of the wtlab repo (the folder that has .git in it).
# It moves everything currently in the repo into a "previous" folder, then adds
# the new pr1..pr8 folders (copied alongside this script) and commits.
#
# Usage:
#   1. cd into your local wtlab repo clone
#   2. copy this script + the pr1..pr8 folders into that repo folder
#   3. run:  bash reorganize.sh
#   4. review with: git status / git diff --stat
#   5. push:  git push

set -e

if [ ! -d ".git" ]; then
  echo "Run this from inside your local wtlab repo (folder containing .git). Aborting."
  exit 1
fi

mkdir -p previous

# Move every existing top-level item (except .git, previous itself, the new prN
# folders, and this script) into previous/
for item in * .[!.]*; do
  [ -e "$item" ] || continue
  case "$item" in
    .git|previous|pr1|pr2|pr3|pr4|pr5|pr6|pr7|pr8|reorganize.sh)
      continue
      ;;
  esac
  git mv "$item" "previous/$item" 2>/dev/null || mv "$item" "previous/$item"
done

git add -A
git commit -m "Reorganize: move existing files into previous/, add pr1-pr8 practicals"

echo "Done. Review with 'git status', then push with 'git push'."
