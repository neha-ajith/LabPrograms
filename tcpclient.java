import java.net.*;
import java.io.*;
import java.util.Scanner;
public class tcpclient
{
    public static void main(String args[]) throws Exception
    {
        Socket s = new Socket("localhost",42069);
        DataInputStream din = new DataInputStream(s.getInputStream());
        DataOutputStream dout = new DataOutputStream(s.getOutputStream());    
        String rev;
        Scanner sc= new Scanner(System.in); //System.in is a standard input stream  
        System.out.print("Enter a string: ");  
        String str= sc.nextLine();              //reads string 
        System.out.print("You have entered: "+str);
        dout.writeUTF(str);
        dout.flush();
        rev = din.readUTF();
        System.out.print("\nThe desired output is: "+rev);  
        dout.close();
        s.close();
    }
}    
