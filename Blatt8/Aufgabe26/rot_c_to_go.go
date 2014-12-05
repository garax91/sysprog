package main

import
(
"os"
"bufio"
"fmt"
//#include "rot13.h"
//#include <stdlib.h>
"C"
)

func main(){
	for{

		reader := bufio.NewReader(os.Stdin)
		fmt.Print("Enter text: ")
		text, _ := reader.ReadString('\n')
		
		C.char bla = C.mallocgc(text.length, string, 0)

		C.CString(text) *C.char
		
		C.GoString(*C.char) text
		fmt.Println(text)
	}
}
