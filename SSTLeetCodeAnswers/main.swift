//
//  main.swift
//  SSTLeetCodeAnswers
//
//  Created by 梅琰培 on 9/1/20.
//  Copyright © 2020 SunshineTeemo. All rights reserved.
//

import Foundation




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



print(rob2([2,7,9,3,1]))



