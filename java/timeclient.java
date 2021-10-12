import java.net.*;
import java.lang.Thread;

public class timeclient
{
    public static void main(String args[]) throws Exception
    {
        DatagramSocket ds = new DatagramSocket();
        InetAddress ip = InetAddress.getByName("localhost");

        byte[] sent_data = new byte[1];
        byte[] received_data = new byte[50];

        System.out.println("Sending request to Server...");
        
        DatagramPacket to_server= new DatagramPacket(sent_data,sent_data.length,ip,6900);    //packet to server
        ds.send(to_server);    
        
        Thread.sleep(1000);
        System.out.println("Request sent..");

        DatagramPacket from_server = new DatagramPacket(received_data,received_data.length); //packet receiving from server
        ds.receive(from_server);

        String time = new String(from_server.getData(),0,from_server.getLength());
        Thread.sleep(1000);
        System.out.println("The time is: " + time);              //print result
        
        ds.close();
     }
}
