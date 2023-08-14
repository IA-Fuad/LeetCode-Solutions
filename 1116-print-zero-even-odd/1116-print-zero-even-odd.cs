using System.Threading;

public class ZeroEvenOdd {
    private int n;
    private SemaphoreSlim zeroSemaphore;
    private SemaphoreSlim oddSemaphore;
    private SemaphoreSlim evenSemaphore;
    private bool releaseOdd = true;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
        zeroSemaphore = new SemaphoreSlim(1, 1);
        oddSemaphore = new SemaphoreSlim(0, 1);
        evenSemaphore = new SemaphoreSlim(0, 1);
    }

    // printNumber(x) outputs "x", where x is an integer.
    public void Zero(Action<int> printNumber) {
        for (int k = 0; k < n; k++) {
            zeroSemaphore.Wait();
            printNumber(0);
            
            if (releaseOdd) {
                oddSemaphore.Release();
            }
            else {
                evenSemaphore.Release();
            }
        }
    }

    public void Even(Action<int> printNumber) {
        for (int k = 2; k <= n; k += 2) {
            evenSemaphore.Wait();
            printNumber(k);
            releaseOdd = !releaseOdd;
            zeroSemaphore.Release();
        }
    }

    public void Odd(Action<int> printNumber) {
        for (int k = 1; k <= n; k += 2) {
            oddSemaphore.Wait();
            printNumber(k);
            releaseOdd = !releaseOdd;
            zeroSemaphore.Release();
        }
    }
}