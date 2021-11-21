//
//  daySchedule.swift
//  OSSCalendar
//
//  Created by JEN Lee on 2021/11/21.
//

import Foundation
import RealmSwift

class daySchedule : Object {
    @objc dynamic var day: String = ""
    @objc dynamic var title: String = ""
    @objc dynamic var privateType = careType.level1.rawValue
    var caretype: careType {
        get { return careType(rawValue: privateType)! }
        set { privateType = newValue.rawValue }
    }
}


enum careType: Int {
    case level1 = 0
    case level2 = 1
    case level3 = 2
    case nolevel = 3
    case none = 4
}
