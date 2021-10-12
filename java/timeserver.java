import java.net.*;
import java.lang.Thread;
import java.util.Date;

public class timeserver
{
    public static void main(String args[]) throws Exception
    {
        DatagramSocket ds = new DatagramSocket(6900);
        byte[] sent_data = new byte[50];
        byte[] received_data = new byte[1];

        DatagramPacket from_client = new DatagramPacket(received_data,received_data.length);    //packet receiving string from client
        ds.receive(from_client);
        InetAddress ip = from_client.getAddress();                      // ip address of client
        int port = from_client.getPort();                               // getting port number
        
       Thread.sleep(1000);
       System.out.println("Request Received..");

       Date d = new Date();
       String time = d + "";
       sent_data = time.getBytes();

       Thread.sleep(1000);
       System.out.println("Request Processed..Sending Data..");
       DatagramPacket to_client = new DatagramPacket(sent_data,sent_data.length,ip,port);    //send data to client
       ds.send(to_client);

       System.out.println("Data successfully transferred..");
       ds.close();

     }
}
