package main

// import (
// 	"fmt"
// 	"log"

// 	"github.com/colinmarc/hdfs"
// 	_ "github.com/vladimirvivien/gowfs"
// )

// func main() {
// 	client, err := hdfs.New("192.168.65.130:9870")
// 	//client, err := hdfs.New("")

// 	fmt.Println(111)
// 	if err != nil {
// 		log.Fatal(err)
// 	}
// 	fmt.Println(222)
// 	file, _ := client.Open("/test/1.txt")

// 	buf := make([]byte, 59)
// 	file.ReadAt(buf, 48847)

// 	fmt.Println(string(buf))
// }

// func main() {
// 	fs, err := gowfs.NewFileSystem(gowfs.Configuration{Addr: "10.177.42.97:15820", User: "root"})
// 	if err != nil {
// 		log.Fatal(err)
// 	}
// 	checksum, err := fs.GetFileChecksum(gowfs.Path{Name: "location/to/file"})
// 	if err != nil {
// 		log.Fatal(err)
// 	}
// 	fmt.Println(checksum)
// }

// import (
// 	"bytes"
// 	_ "errors"
// 	_ "io"
// 	"io/ioutil"
// 	"net/http"
// 	_ "os"
// 	"path"

// 	"fmt"
// )

/* webHDFS方式：此处仅作实例，直接填写的为datanode地址，若改为namenode地址，则需要重定向到datanode
后再调用
    httpfs方式：直接填写namenode地址，无需重定向
*/
//var HDFSURLPrefix = "http://192.168.65.130:9870/webhdfs/v1"
// var HDFSURLPrefix = "http://diy2.bigdata.ly:50070/webhdfs/v1"

// func createFromData(bucket string, fileName string, data []byte) error {
// 	url := HDFSURLPrefix + "/" + path.Join(bucket, fileName) + "?op=create&data=true&user.name=root"

// 	req, err := http.NewRequest("PUT", url, bytes.NewReader(data))
// 	if err != nil {
// 		fmt.Println(fmt.Errorf("url(%v) NewRequest: %v", url, err))
// 		return err
// 	}
// 	req.Header.Set("Content-Type", "application/octet-stream")

// 	rep, err := http.DefaultClient.Do(req)
// 	if err != nil {
// 		fmt.Println(fmt.Errorf("url(%v) DefaultClient.Do: %v", url, err))
// 		return err
// 	}

// 	if rep.StatusCode != http.StatusCreated {
// 		fmt.Println(fmt.Errorf("url(%v) rep not ok, req(%v)", url, rep))
// 		return err
// 	}

// 	body, err := ioutil.ReadAll(rep.Body)
// 	if err != nil {
// 		fmt.Println(fmt.Errorf("url(%v) rep body read failed: %v", url, err))
// 		return err
// 	}

// 	fmt.Printf("url(%v) get req ok, body(%v)\n", url, string(body))
// 	return nil
// }

// func main() {
// 	data, err := ioutil.ReadFile("/home/test.json")
// 	if err != nil {
// 		fmt.Println(fmt.Errorf("read file failed:%v", err))
// 		return
// 	}

// 	err = createFromData("", "test.json", data)
// 	if err != nil {
// 		fmt.Println(fmt.Errorf("create hdfs file failed:%v", err))
// 		return
// 	}
// }

//注意：
////以上代码仅简单的实现了上传一个本地文件到HDFS的功能。针对较大文件，此代码并不实用（单次readAll不合理）。这时候可以使用Append接口对大文件进行分段上传。

//另外，需要注意HDFS的namenode和datanode区别，由于hdfs一般部署在集群环境中，直接访问datanode不太现实。webHDFS调用时需要通过namenode重定向到datanode。为避免此情况，建议调整为httpfs方式，直接访问namenode地址。
