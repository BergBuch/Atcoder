import math
#N以下の素数を求める
def calc_prime(N):
    is_prime = [True for _ in range(N+1)]
    is_prime[0] = False
    is_prime[1] = False
    i=0
    while i*i <= N:
        #素数じゃなかったら飛ばす
        if not is_prime[i]:
            i+=1
            continue

        #素数ならその倍数をFalseにしていく
        j=i*2
        while j <= N:
            is_prime[j] = False
            j+=i
        
        i+=1
    
    primes = []
    for i in range(N+1):
        if is_prime[i]: primes.append(i)
    
    return primes

#メイン
n = int(input())
primes = calc_prime(int(math.sqrt(n/12)))
count = 0
for i in range(len(primes)):
    k = len(primes)-1
    for j in range(i+1,len(primes)):
        while j<k:
            f = primes[i]*primes[i]*primes[j]*primes[k]*primes[k]
            if f > n:
                k -= 1
                continue

            if f <= n:
                count += k-j
                break
        if j>=k: break

print(count)