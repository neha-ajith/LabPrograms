import java.net.*;
import java.io.*;

public class tcpserver
{
    public static void main(String args[]) throws Exception
    {
        ServerSocket ss = new ServerSocket(42069);
        Socket s = ss.accept();
        DataInputStream din = new DataInputStream(s.getInputStream());
        DataOutputStream dout = new DataOutputStream(s.getOutputStream());
        String str;
        str = din.readUTF();
        System.out.print("Server Running");
        char st[] = str.toCharArray();
        String rev = "";
        for (int i = st.length - 1; i >= 0; --i) 
        {
         if(Character.isUpperCase(st[i]))
              rev += Character.toLowerCase(st[i]); 
        else
            rev += Character.toUpperCase(st[i]);  
        }   
        dout.writeUTF(rev);
        dout.flush();
        din.close();
        s.close();
        ss.close();
    }
}
