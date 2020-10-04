# git cheat sheet

## git file types
  * blob
  * trees
  * commit
  * annotated tags

## Commands
 * git init -> create new repo on local
 * git clone <repo-url> -> copy repo on local
 * git status
 * git add -A -> add all modified/created/deleted files for the next commit
 * git commit -m"<commit-message>" -> create commit on LOCAL
 * git branch -> create new brach at the current commmit
 * git merge <branch-name>
 * git log -> show all commits in the current branch's history
 * git fetch -> fetch ALL branches from the server
 * git push -> push all commits on the server
 * git pull -> fetch + merge on the tracking branch
 * git rebase [-i] <branch> -> rebase on <branch> [interactive]
 * git checkout <branch_name/SHA1> -> switch the HEAD on branch/commit 