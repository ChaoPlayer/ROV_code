;; Auto-generated. Do not edit!


(when (boundp 'control_pkg::servo_control)
  (if (not (find-package "CONTROL_PKG"))
    (make-package "CONTROL_PKG"))
  (shadow 'servo_control (find-package "CONTROL_PKG")))
(unless (find-package "CONTROL_PKG::SERVO_CONTROL")
  (make-package "CONTROL_PKG::SERVO_CONTROL"))
(unless (find-package "CONTROL_PKG::SERVO_CONTROLREQUEST")
  (make-package "CONTROL_PKG::SERVO_CONTROLREQUEST"))
(unless (find-package "CONTROL_PKG::SERVO_CONTROLRESPONSE")
  (make-package "CONTROL_PKG::SERVO_CONTROLRESPONSE"))

(in-package "ROS")





(defclass control_pkg::servo_controlRequest
  :super ros::object
  :slots (_req _servoID ))

(defmethod control_pkg::servo_controlRequest
  (:init
   (&key
    ((:req __req) "")
    ((:servoID __servoID) 0)
    )
   (send-super :init)
   (setq _req (string __req))
   (setq _servoID (round __servoID))
   self)
  (:req
   (&optional __req)
   (if __req (setq _req __req)) _req)
  (:servoID
   (&optional __servoID)
   (if __servoID (setq _servoID __servoID)) _servoID)
  (:serialization-length
   ()
   (+
    ;; string _req
    4 (length _req)
    ;; uint8 _servoID
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _req
       (write-long (length _req) s) (princ _req s)
     ;; uint8 _servoID
       (write-byte _servoID s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _req
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _req (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _servoID
     (setq _servoID (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass control_pkg::servo_controlResponse
  :super ros::object
  :slots (_angle ))

(defmethod control_pkg::servo_controlResponse
  (:init
   (&key
    ((:angle __angle) 0.0)
    )
   (send-super :init)
   (setq _angle (float __angle))
   self)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:serialization-length
   ()
   (+
    ;; float32 _angle
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _angle
     (setq _angle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass control_pkg::servo_control
  :super ros::object
  :slots ())

(setf (get control_pkg::servo_control :md5sum-) "e95109d072a249ed2c81c45a1a6b292a")
(setf (get control_pkg::servo_control :datatype-) "control_pkg/servo_control")
(setf (get control_pkg::servo_control :request) control_pkg::servo_controlRequest)
(setf (get control_pkg::servo_control :response) control_pkg::servo_controlResponse)

(defmethod control_pkg::servo_controlRequest
  (:response () (instance control_pkg::servo_controlResponse :init)))

(setf (get control_pkg::servo_controlRequest :md5sum-) "e95109d072a249ed2c81c45a1a6b292a")
(setf (get control_pkg::servo_controlRequest :datatype-) "control_pkg/servo_controlRequest")
(setf (get control_pkg::servo_controlRequest :definition-)
      "string req
uint8 servoID
---
float32 angle
")

(setf (get control_pkg::servo_controlResponse :md5sum-) "e95109d072a249ed2c81c45a1a6b292a")
(setf (get control_pkg::servo_controlResponse :datatype-) "control_pkg/servo_controlResponse")
(setf (get control_pkg::servo_controlResponse :definition-)
      "string req
uint8 servoID
---
float32 angle
")



(provide :control_pkg/servo_control "e95109d072a249ed2c81c45a1a6b292a")


