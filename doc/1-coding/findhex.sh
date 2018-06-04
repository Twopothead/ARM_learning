cd 战舰_标准例程-库函数版本
for file in *
do
	if test -d $file	
	then
		cd $file
		#echo $(pwd)$file
		if test -d "OBJ"
		then
			cd OBJ
			for hexfile in `find $(pwd) -name "*.hex"`
			do
			
	   		echo "#""loadbin "$hexfile" 0x08000000"
			cd ..
			done 
		fi
		cd ..
	fi
done
