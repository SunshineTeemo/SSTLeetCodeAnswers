import Foundation

//基本排序算法

//1.冒泡排序算法
func testBubbleSort() {
    var array = [1,3,9,8,65,0,28,46,129]
    bubbleSortAlgorithm(array: &array)
    print(array)
}

func bubbleSortAlgorithm( array: inout [Int]) {
    for i in 0..<array.count-1 {
        for j in 0..<array.count-1-i {
            if array[j] > array[j+1] {
                let value = array[j+1]
                array[j+1] = array[j]
                array[j] = value
            }
        }
    
    }
}
