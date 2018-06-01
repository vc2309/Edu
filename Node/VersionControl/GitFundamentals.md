#Git

## Basic Commands

### Setup a repo locally
- enter target directory
- `git init`
- This establishes a git repo in this directory

### Committing
-`git status`
- This tells us which files are untracked, tracked, modified, deleted, added etc
- `git add <filenames>` will add any untracked files to the files which you want the repo to track
- `git commit -m"message"`

###.gitignore
- This is a file which contains any files/folders which we dont want the repo to track or add
- `echo 'node_modules/' >> .gitignore`
