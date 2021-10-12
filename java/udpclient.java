import java.net.*;
import java.util.Scanner;
import java.lang.Thread;

public class udpclient
{
    public static void main(String args[]) throws Exception
    {
        DatagramSocket ds = new DatagramSocket();                                       //socket to send data to server
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = sc.nextLine();
        System.out.print("Enter character to find the occurence of: ");
        String ch = sc.nextLine();
        
        InetAddress ip = InetAddress.getByName("127.0.0.1");
        
        DatagramPacket dp = new DatagramPacket(str.getBytes(),str.length(),ip,3000);    //send string to server
        ds.send(dp);
        Thread.sleep(1000);
        DatagramPacket cp = new DatagramPacket(ch.getBytes(),ch.length(),ip,3000);      //send character to server
        ds.send(cp);
        ds.close();                                                                     //close sending socket    
        
        DatagramSocket result = new DatagramSocket(4000);                               //socket to receive data from server
        byte[] cbuf = new byte[1];
        
        DatagramPacket res = new DatagramPacket(cbuf,1);                                //packet receiving from server
        result.receive(res);
        String val = new String(res.getData(),0,res.getLength());
        
        System.out.print("The number of occurences of "+ch+" is: "+val+"\n");              //print result
        result.close();
     }
}        
