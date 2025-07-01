;; Auto-generated. Do not edit!


(when (boundp 'rov_start_pkg::init_msg)
  (if (not (find-package "ROV_START_PKG"))
    (make-package "ROV_START_PKG"))
  (shadow 'init_msg (find-package "ROV_START_PKG")))
(unless (find-package "ROV_START_PKG::INIT_MSG")
  (make-package "ROV_START_PKG::INIT_MSG"))

(in-package "ROS")
;;//! \htmlinclude init_msg.msg.html


(defclass rov_start_pkg::init_msg
  :super ros::object
  :slots (_command _success _module_name _check_status ))

(defmethod rov_start_pkg::init_msg
  (:init
   (&key
    ((:command __command) nil)
    ((:success __success) nil)
    ((:module_name __module_name) "")
    ((:check_status __check_status) nil)
    )
   (send-super :init)
   (setq _command __command)
   (setq _success __success)
   (setq _module_name (string __module_name))
   (setq _check_status __check_status)
   self)
  (:command
   (&optional (__command :null))
   (if (not (eq __command :null)) (setq _command __command)) _command)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:module_name
   (&optional __module_name)
   (if __module_name (setq _module_name __module_name)) _module_name)
  (:check_status
   (&optional (__check_status :null))
   (if (not (eq __check_status :null)) (setq _check_status __check_status)) _check_status)
  (:serialization-length
   ()
   (+
    ;; bool _command
    1
    ;; bool _success
    1
    ;; string _module_name
    4 (length _module_name)
    ;; bool _check_status
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _command
       (if _command (write-byte -1 s) (write-byte 0 s))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _module_name
       (write-long (length _module_name) s) (princ _module_name s)
     ;; bool _check_status
       (if _check_status (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _command
     (setq _command (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _module_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _module_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _check_status
     (setq _check_status (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get rov_start_pkg::init_msg :md5sum-) "d2995b634e846547e16a64fc61dda91c")
(setf (get rov_start_pkg::init_msg :datatype-) "rov_start_pkg/init_msg")
(setf (get rov_start_pkg::init_msg :definition-)
      "bool command
bool success
string module_name
bool check_status

")



(provide :rov_start_pkg/init_msg "d2995b634e846547e16a64fc61dda91c")


