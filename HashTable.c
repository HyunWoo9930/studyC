/**
 * Mid-square : 제곱해서 중간수
 * Division : 소수로 나눈 나머지로
 * Folding : 나눠서 더해주는 방식 94037 -> 94 + 03 + 7 = 104
 *
 * 해시 테이블 종류
 * Linear Probing : 다음 배열을 찾아가는 방식
 * - Clustering , Coalescing이 발생
 * Quadratic Probing : 제곱씩으로 늘어남 h + 1 / h + 4 / h + 9
 * Double Hashing(Rehashing) : 새로운 h(2) 함수를 만들어서 h(1)에 더해주는 방식
 * Chaining : 똑같은 hash들을 배열로 묶어서 하는 방법
 *
 * 적재율 a : n / M (n개의 요소, M개의 buckets)
 *  Linear Probing 적재율 :
 *      1) 존재하지 않는 요소 : 1/2 * (1 + 1 / (1-a)^2)
 *      2) 존재하는 요소     : 1/2 * (1 + 1 / (1-a))
 *  Chaining 적재율 :
 *      1) 존재하지 않는 요소 : a
 *      2) 존재하는 요소     : 1 + a / 2
 * **/