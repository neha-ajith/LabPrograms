import java.lang.*;
public class ThreadIdExample
{
public static void main(String[] args)
{
WorkerThread workerthreadobject = new WorkerThread();
// below is the first constructor : setting name also
Thread t1 = new Thread(workerthreadobject);
t1.setName("First Thread");
t1.start();
// below is the second constructor : setting name as argument
Thread t2 = new Thread(workerthreadobject, "Second Thread");
t2.start();
// below we will not set any name of the thread
Thread t3 = new Thread(workerthreadobject);
t3.start();
// Getting the current thread object i.e Main thread
Thread currentThread = Thread.currentThread();
// Printing Main thread : name and id
System.out.println("\nExecuting thread: " + currentThread.getName()) ;
System.out.println("\nID of the thread is " + currentThread.getId());
}
}
class WorkerThread implements Runnable{
@Override
public void run() {
// get current thread instance
Thread t = Thread.currentThread();
// call thread.getId() on the current t instance
System.out.println("\nWorkerThread details: Name- "+ t.getName());
System.out.println("\nThread Id of Worker Thread- " + t.getId());
}
}