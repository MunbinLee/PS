// \
/*
#include <iostream>
using namespace std;
// \
*/
// \
import java.io.*;public class Main {public static void main(String[] args) throws IOException {BufferedReader br = new BufferedReader(new InputStreamReader(System.in));int n = Integer.parseInt(br.readLine());String res;
// \
/*
int main() {int n;cin >> n;string res;



// \
*/
if (n == 0) {res = "0";}
/*
 /*
 asd
 */
// \
 */
else if (n == 1) {res = "01";}
else if (n == 2) {res = "0110";}
else if (n == 3) {res = "011011";}
else if (n == 4) {res = "011011100";}
else if (n == 5) {res = "011011100101";}
else if (n == 6) {res = "011011100101110";}
else if (n == 7) {res = "011011100101110111";}
else if (n == 8) {res = "0110111001011101111000";}
else if (n == 9) {res = "01101110010111011110001001";}
else {res = "011011100101110111100010011010";}
// \
System.out.println(res);
// \
/*
cout << res;
// \
*/
}
// \
}