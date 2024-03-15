public class Comparison {

    private static void garbageCollect() {
        // Suggests garbage collection to the JVM
        System.gc();
        // Pause to give garbage collector a chance to run
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }


    private static long getUsedMemory() {
        // Get the instance of runtime
        Runtime runtime = Runtime.getRuntime();
        // Calculate used memory by subtracting free memory from total memory
        return runtime.totalMemory() - runtime.freeMemory();
    }

    public static void main(String[] args) {

        garbageCollect();
        long bgddemoryBefore = getUsedMemory();
        long bgdstartTime = System.nanoTime();
        BasicGradientDescent.run();
        long bgdendTime = System.nanoTime();
        long bgdnanosecondsRun = bgdendTime - bgdstartTime;
        garbageCollect();
        long bgdmemoryAfter = getUsedMemory();
        long bgdmemory = bgdmemoryAfter - bgddemoryBefore;


        garbageCollect();
        long sbgdemoryBefore = getUsedMemory();
        long sgdstartTime = System.nanoTime();
        QuadraticMinimizerSGA.run();
        long sgdendTime = System.nanoTime();
        long sgdnanosecondsRun = sgdendTime - sgdstartTime;
        garbageCollect();
        long sgdmemoryAfter = getUsedMemory();
        long sgdmemory = sgdmemoryAfter - sbgdemoryBefore;



        // ------

        System.out.println("--------------");
        System.out.println("Summary of comparison");
        System.out.println("--------------");

        System.out.println("------- execution time---------");
        System.out.println("BGD nanoseconds: " + bgdnanosecondsRun);
        System.out.println("SGD nanoseconds: " + sgdnanosecondsRun);
        if(bgdnanosecondsRun < sgdnanosecondsRun) {
            System.out.println("BGD was faster by (nanoseconds):" + (sgdnanosecondsRun - bgdnanosecondsRun));
        } else {
            System.out.println("SGD was faster by (nanoseconds):" + (bgdnanosecondsRun - sgdnanosecondsRun));
        }

        System.out.println("------- memory consumption ---------");
        System.out.println("BGD ram bytes: " + bgdmemory);
        System.out.println("SGD ram: " + sgdmemory);
        if(bgdmemory < sgdmemory) {
            System.out.println("BGD consumped less memory by (bytes):" + (bgdmemory - sgdmemory));
        } else {
            System.out.println("BGD consumped less memory by (bytes)" + (sgdmemory - bgdmemory));
        }


    }
}
