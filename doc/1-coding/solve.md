### 1.解压rar压缩文件乱码问题

```sh
file -i 要查看其编码的文件.txt
```

```shell
sudo apt-get install enca
enca -L zh_CN -x utf-8 *
```

