//
//  main.swift
//  SSTLeetCodeAnswers
//
//  Created by 梅琰培 on 9/1/20.
//  Copyright © 2020 SunshineTeemo. All rights reserved.
//

import Foundation


//printHellow()


//MARK:- 计数质数
//https://leetcode-cn.com/problems/count-primes/

func countPrimes(_ n: Int) -> Int {
    
    if n <= 2 {
        return 0
    }
    


    //先假设所有数都是质数，然后排除所有合数
    var array = Array.init(repeating: true, count: n)

    var i = 2
    while i*i <= n {
        
        if array[i] == true {
            
            var  j = i
            
            while i*j < n {
                array[i*j] = false
                
                
                j += 1
            }
    
        }
        
        
        i += 1
    }
    

   
    //计算剩下的质数，注意0、1不是质数
    var count = 0
    
    for i in 2..<n {
        
        if array[i] == true {
            count += 1
        }
   
    }

    return count

}


print(countPrimes(2))


//MARK:- 203.移除链表数据
//https://leetcode-cn.com/problems/remove-linked-list-elements/

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
    
}


func removeElements(_ head: ListNode?, _ val: Int) -> ListNode? {
    
    if head == nil {
        return nil
    }
    
    if head!.val == val{
        return removeElements(head!.next, val)
    }else
    {
        head!.next = removeElements(head!.next, val)
        
        return head
    }


}



//MARK:- 202.快乐数
//https://leetcode-cn.com/problems/happy-number/


//方法二 快慢指针
func isHappy2(_ n: Int) -> Bool {

    var slow = getNextValue(n)
    
    var fast = getNextValue(slow)
    
    while slow != 1 && slow != fast {
        slow = getNextValue(slow)
        
        fast = getNextValue(getNextValue(fast))
    }
    
    return slow == 1
    
    
}
func getNextValue(_ number: Int) -> Int
{
    var sum = 0
    var n = number
    
    while n != 0 {
           
        let reminder = n%10

        sum += reminder*reminder
           
        n /= 10

    }
    return sum
}



//方法一
func isHappy(_ n: Int) -> Bool {

    var array = [n]
    
    var number = n
   
    return isHappy(&number, &array)
    
    
}


func isHappy(_ number: inout Int,_ array: inout [Int] ) -> Bool{
    
    if number == 1{
        return true
    }
    var sum = 0
       
    while number != 0 {
           
        let reminder = number%10

        sum += reminder*reminder
           
        number /= 10

    }
    print(number,sum)
    
    if array.contains(sum)
    {
        return false
    }else{
           
        array.append(sum)
        return isHappy(&sum, &array)
    }
    
}


//print(isHappy2(12))



//MARK:- 198.打家劫舍
//https://leetcode-cn.com/problems/house-robber/
func rob(_ nums: [Int]) -> Int {
    
    
    if nums.isEmpty {
        return 0
    }
    
    
    if nums.count == 1{
        return nums.first!
    }
    
    var max = 0
    
    var secondMax = 0
    var maxIndex = 0
    
    
    for (index,value) in nums.enumerated() {
        
        if index == 0 {
            max = value

        }else{
            
            if index - maxIndex == 1 {
                
                if  max < value + secondMax{
                    
                    let temp = max
                    max = value + secondMax

                    secondMax = temp
                    maxIndex = index
                    
                    
                }else{
                    secondMax = value + secondMax
                    
                    
                }
               
                
            }else if index - maxIndex > 1{
              
                secondMax = max
                max = max + value
                maxIndex = index
                
                
            }
        }
        
        
        
    }
    
    
    return max
}

func rob2(_ nums: [Int]) -> Int {
    
    
    if nums.isEmpty {
        return 0
    }
    
    
    if nums.count == 1{
        return nums.first!
    }
    
    
    //不偷窃second对应index的房屋的最大金额
    var first = nums[0]
    
    //表示偷窃对应index房屋的最大金额
    var second = nums[1]
    
    
    for index in 2..<nums.count {
        
        let temp = first
             
        first = max(first, second)
        second = temp + nums[index]
        
    }
 
    return max(first, second)
}



//print(rob2([2,7,9,3,1]))



