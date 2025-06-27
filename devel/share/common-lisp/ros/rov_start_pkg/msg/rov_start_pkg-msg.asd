
(cl:in-package :asdf)

(defsystem "rov_start_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "init_msg" :depends-on ("_package_init_msg"))
    (:file "_package_init_msg" :depends-on ("_package"))
  ))