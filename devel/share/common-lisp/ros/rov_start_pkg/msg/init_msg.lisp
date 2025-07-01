; Auto-generated. Do not edit!


(cl:in-package rov_start_pkg-msg)


;//! \htmlinclude init_msg.msg.html

(cl:defclass <init_msg> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:boolean
    :initform cl:nil)
   (success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (module_name
    :reader module_name
    :initarg :module_name
    :type cl:string
    :initform "")
   (check_status
    :reader check_status
    :initarg :check_status
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass init_msg (<init_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <init_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'init_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rov_start_pkg-msg:<init_msg> is deprecated: use rov_start_pkg-msg:init_msg instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <init_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rov_start_pkg-msg:command-val is deprecated.  Use rov_start_pkg-msg:command instead.")
  (command m))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <init_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rov_start_pkg-msg:success-val is deprecated.  Use rov_start_pkg-msg:success instead.")
  (success m))

(cl:ensure-generic-function 'module_name-val :lambda-list '(m))
(cl:defmethod module_name-val ((m <init_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rov_start_pkg-msg:module_name-val is deprecated.  Use rov_start_pkg-msg:module_name instead.")
  (module_name m))

(cl:ensure-generic-function 'check_status-val :lambda-list '(m))
(cl:defmethod check_status-val ((m <init_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rov_start_pkg-msg:check_status-val is deprecated.  Use rov_start_pkg-msg:check_status instead.")
  (check_status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <init_msg>) ostream)
  "Serializes a message object of type '<init_msg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'command) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'module_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'module_name))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'check_status) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <init_msg>) istream)
  "Deserializes a message object of type '<init_msg>"
    (cl:setf (cl:slot-value msg 'command) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'module_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'module_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'check_status) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<init_msg>)))
  "Returns string type for a message object of type '<init_msg>"
  "rov_start_pkg/init_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'init_msg)))
  "Returns string type for a message object of type 'init_msg"
  "rov_start_pkg/init_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<init_msg>)))
  "Returns md5sum for a message object of type '<init_msg>"
  "d2995b634e846547e16a64fc61dda91c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'init_msg)))
  "Returns md5sum for a message object of type 'init_msg"
  "d2995b634e846547e16a64fc61dda91c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<init_msg>)))
  "Returns full string definition for message of type '<init_msg>"
  (cl:format cl:nil "bool command~%bool success~%string module_name~%bool check_status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'init_msg)))
  "Returns full string definition for message of type 'init_msg"
  (cl:format cl:nil "bool command~%bool success~%string module_name~%bool check_status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <init_msg>))
  (cl:+ 0
     1
     1
     4 (cl:length (cl:slot-value msg 'module_name))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <init_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'init_msg
    (cl:cons ':command (command msg))
    (cl:cons ':success (success msg))
    (cl:cons ':module_name (module_name msg))
    (cl:cons ':check_status (check_status msg))
))
