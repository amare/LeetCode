Some Script
======

### readme.sh
`readme.sh` - it's used to generate the table items in README.md located in LeetCode directory
For Example:
```
$ ./Scripts/readme.sh 062_Unique_Paths/unique_paths.h
|62|[Unique Paths][62]|[C++](./062_Unique_Paths/unique_paths.h)|Medium|2017/03/25|
[62]:https://leetcode.com/problems/unique-paths/#/description
```

### gitpush.sh
`gitpush.sh` - it's used to push the code to github using one command
>Note: When using `git status -s` command, the result should be like `?? 062_Unique_Paths/`.
>In other word, the result should match regular expression `/^\?.*[0-9]/`

For Example:
```
$  ./Scripts/gitpush.sh
file name: ./Scripts/gitpush.sh
[master 4d5fc64] add Unique Paths
 2 files changed, 91 insertions(+)
 create mode 100755 062_Unique_Paths/README.md
 create mode 100755 062_Unique_Paths/unique_paths.h
对象计数中: 5, 完成.
Delta compression using up to 4 threads.
压缩对象中: 100% (5/5), 完成.
写入对象中: 100% (5/5), 1.25 KiB | 0 bytes/s, 完成.
Total 5 (delta 1), reused 0 (delta 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local objects.
To git@github.com:amare/LeetCode.git
   2da8fba..4d5fc64  master -> master

```
