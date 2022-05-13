package main

// import (
// 	"fmt"
// 	"github.com/vladimirvivien/gowfs"
// 	_ "io/ioutil"
// )

// func main() {
// 	//这是配置，传入Addr: "ip: 50070", User: "随便写一个英文名就行"
// 	config := gowfs.Configuration{Addr: "192.168.65.130:9870", User: "root"}
// 	//返回一个客户端(这里面叫文件系统)和error
// 	client, err := gowfs.NewFileSystem(config)
// 	if err != nil {
// 		panic(fmt.Sprintln("出现异常,异常信息为:", err))
// 	}
// 	fmt.Println(1111)
// 	//这里不能直接传入文件名，而是需要作为gowfs.Path结构体的Name参数的值
// 	//然后将Path传进去，我们后面的api都是这样做的
// 	path := gowfs.Path{Name: "/lypfiles/start-all.sh"}

// 	//接收如下参数：gowfs.Path,offset(偏移量),长度(显然是字节的长度), 容量(自己的cap)
// 	//返回一个io.ReadCloser，这是需要实现io.Reader和io.Closer的接口
// 	reader, _ := client.Open(path, 0, 512, 2048)
// 	fmt.Println(2222)
// 	var buf []byte
// 	//可以使用reader.Read(buf)的方式循环读取，也可以丢给ioutil。ReadAll，一次性全部读取
// 	reader.Read(buf)
// 	//data, _ := ioutil.ReadAll(reader)
// 	//fmt.Println(string(data))
// 	fmt.Println(string(buf))
// 	/*
// 		白色相簿什么的，已经无所谓了。
// 		因为已经不再有歌，值得去唱了。
// 		传达不了的恋情，已经不需要了。
// 		因为已经不再有人，值得去爱了。
// 	*/
// }

// package main

// import (
// 	"fmt"
// 	"github.com/vladimirvivien/gowfs"
// )

// func main() {
// 	//fail
// 	config := gowfs.Configuration{Addr: "192.168.65.130:9870", User: "root"}
// 	//ok
// 	//config := gowfs.Configuration{Addr: "diy2.bigdata.ly:50070", User: "dcadmin"}
// 	//fail
// 	//config := gowfs.Configuration{Addr: "10.177.42.98:15821", User: "hadoop"}
// 	client, err := gowfs.NewFileSystem(config)
// 	if err != nil {
// 		panic(fmt.Sprintln("出现异常,异常信息为:", err))
// 	}

// 	path := gowfs.Path{Name: "/"}
// 	// 返回[]FileStatus和error
// 	//这个FileStatus是什么？我们看一下源码
// 	/*
// 		type FileStatus struct {
// 			AccesTime        int64  访问时间
// 			BlockSize        int64  块大小,只针对文件(134217728 Bytes,128 MB)，目录的话为0
// 			Group            string 所属组
// 			Length           int64  文件的字节数(目录为0)
// 			ModificationTime int64  修改时间
// 			Owner            string 所有者
// 			PathSuffix       string 文件后缀，说白了就是文件名
// 			Permission       string 权限
// 			Replication      int64  副本数
// 			Type             string 类型，文本的话是FILE，目录的话是DIRECTORY
// 		}
// 	*/
// 	fs_arr, _ := client.ListStatus(path)
// 	fmt.Println(fs_arr)
// 	// [{0 0 supergroup 0 1570359570447 dr.who tkinter 755 0 DIRECTORY} {0 134217728 supergroup 184 1570359155457 root whitealbum.txt 644 1 FILE}]

// 	for _, fs := range fs_arr {
// 		fmt.Println("文件名：", fs.PathSuffix)
// 		/*
// 			文件名： tkinter
// 			文件名： whitealbum.txt
// 		*/
// 	}

// 	//FileStatus里面包含了文件的详细信息，如果想查看某个文件的详细信息
// 	//可以使用fs, err := client.GetFileStatus(path)
// 	fmt.Println("exit")
// }

// package main

import (
	"fmt"
	"log"

	"github.com/colinmarc/hdfs"
)

func main() {
	//client, err := hdfs.New("192.168.65.130:9870")
	client, err := hdfs.New("diy2.bigdata.ly:50070")
	if err != nil {
		log.Fatal(err)
	}
	err = client.Remove("/test/1.txt")
	fmt.Println(err)
}
