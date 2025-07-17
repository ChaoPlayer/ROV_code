
(cl:in-package :asdf)

(defsystem "control_pkg-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "servo_control" :depends-on ("_package_servo_control"))
    (:file "_package_servo_control" :depends-on ("_package"))
  ))