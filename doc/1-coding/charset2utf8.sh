cd 战舰_标准例程-库函数版本
for file in *
do
	if test -d $file	
	then
		cd $file
		#echo $(pwd)$file
		if test -d "USER"
		then
			cd USER
			for file in *
			do
				if test -f $file
				then 
					echo "converting to UTF8...:"$file 
					enca -L zh_CN -x UTF-8 $file
				fi
			done	
			cd ..
		fi
		cd ..
	fi
done
#此函数作用:在ubuntu解压rar后因为编码问题会乱码，这里统一转化为UTF8编码
#sudo apt-get install enca
#安装unar
#unar 可能解压后乱码的压缩包.zip 


