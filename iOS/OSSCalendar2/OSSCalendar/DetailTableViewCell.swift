//
//  DetailTableViewCell.swift
//  OSSCalendar
//
//  Created by JEN Lee on 2021/11/21.
//

import UIKit
import RealmSwift

class DetailTableViewCell: UITableViewCell {

    
    let realm = try! Realm()
    var deleteBtn = UIButton()
    var scheduleLabel = UILabel()
    var typeLabel = UILabel()
    var schedule: daySchedule? = nil
    
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        addSubview(deleteBtn)
        addSubview(scheduleLabel)
        addSubview(typeLabel)
        
        
        configureDeleteBtn()
        configureScheduleLabel()
        configureTypeLabel()
        
        setConstraint()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    func set(schedule: daySchedule) {
        self.schedule = schedule
        scheduleLabel.text = schedule.title
        
        switch schedule.privateType {
        case 0:
            typeLabel.text = "난이도1"
        case 1:
            typeLabel.text = "난이도2"
        case 2:
            typeLabel.text = "난이도3"
        case 3:
            typeLabel.text = "난이도없음"
        default:
            typeLabel.text = "선택 사항 없음"
        }
        
    }
    
    func configureDeleteBtn() {
        deleteBtn.translatesAutoresizingMaskIntoConstraints = false
        deleteBtn.backgroundColor = .systemBlue
        deleteBtn.setTitle("삭제", for: .normal)
        deleteBtn.addTarget(self, action: #selector(deleteSchedule), for: .touchUpInside)
    }
    
    @objc func deleteSchedule() {
        if let schedule = schedule {
            do{
                try realm.write{
                    print(schedule)
                    realm.delete(schedule)
                }
            } catch {
                print("Error Delete \(error)")
            }
        }
    }
    
    func configureScheduleLabel() {
        scheduleLabel.translatesAutoresizingMaskIntoConstraints = false
        scheduleLabel.numberOfLines = 0
        scheduleLabel.adjustsFontSizeToFitWidth = true
    }
    
    func configureTypeLabel() {
        typeLabel.translatesAutoresizingMaskIntoConstraints = false
        typeLabel.textColor = .darkGray
    }
    
    
    func setConstraint() {
        NSLayoutConstraint.activate([
            scheduleLabel.topAnchor.constraint(equalTo: topAnchor, constant: 18),
            scheduleLabel.leadingAnchor.constraint(equalTo: leadingAnchor, constant: 20)
        ])
        
        NSLayoutConstraint.activate([
            deleteBtn.centerYAnchor.constraint(equalTo: centerYAnchor),
            deleteBtn.trailingAnchor.constraint(equalTo: trailingAnchor, constant: -20)
        ])
        
        NSLayoutConstraint.activate([
            typeLabel.topAnchor.constraint(equalTo: scheduleLabel.bottomAnchor, constant: 8),
            typeLabel.leadingAnchor.constraint(equalTo: leadingAnchor, constant: 20)
        ])
    }
    

}
