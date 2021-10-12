import java.net.*;
import java.util.Scanner;
import java.lang.Thread;

public class udpserver
{
    public static void main(String args[]) throws Exception
    {
        int count = 0;
        
        DatagramSocket ds = new DatagramSocket(3000);                            //socket to receive client data
        
        byte[] buf = new byte[1024];
        byte[] cbuf = new byte[1];
        
        DatagramPacket dp = new DatagramPacket(buf,1024);                        //packet receiving string from client
        ds.receive(dp);
        String str = new String(dp.getData(),0,dp.getLength());
        
        System.out.print("String received: "+str+"\n");
        
        DatagramPacket cp = new DatagramPacket(cbuf,1);                          //packet receiving character from client
        ds.receive(cp);
        String ch = new String(cp.getData(),0,cp.getLength());
        
        System.out.print("Character received: "+ch+"\n");
        ds.close();                                                              //close receiving socket      

        DatagramSocket result = new DatagramSocket();                            //socket to send data to client
        
        char[] test=ch.toCharArray();
        
        for(int i = 0;i < str.length();i++)                                      //find character occurence
        {
            if(str.charAt(i) == test[0])
                count ++;
        }
        
        InetAddress ip = InetAddress.getByName("127.0.0.1");         
        String val = Integer.toString(count);                                   //convert int to string for transfer
        
        System.out.print("Count found. Sending data..\n");
        DatagramPacket res = new DatagramPacket(val.getBytes(),val.length(),ip,4000);    //send data to client
        result.send(res);
        
        result.close();                                                         //close sending socket
        
     }
}        
