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



print(rob([2,1,1,2]))



