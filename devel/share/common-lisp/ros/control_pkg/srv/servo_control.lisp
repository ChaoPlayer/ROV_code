; Auto-generated. Do not edit!


(cl:in-package control_pkg-srv)


;//! \htmlinclude servo_control-request.msg.html

(cl:defclass <servo_control-request> (roslisp-msg-protocol:ros-message)
  ((req
    :reader req
    :initarg :req
    :type cl:string
    :initform "")
   (servoID
    :reader servoID
    :initarg :servoID
    :type cl:fixnum
    :initform 0))
)

(cl:defclass servo_control-request (<servo_control-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <servo_control-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'servo_control-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_pkg-srv:<servo_control-request> is deprecated: use control_pkg-srv:servo_control-request instead.")))

(cl:ensure-generic-function 'req-val :lambda-list '(m))
(cl:defmethod req-val ((m <servo_control-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_pkg-srv:req-val is deprecated.  Use control_pkg-srv:req instead.")
  (req m))

(cl:ensure-generic-function 'servoID-val :lambda-list '(m))
(cl:defmethod servoID-val ((m <servo_control-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_pkg-srv:servoID-val is deprecated.  Use control_pkg-srv:servoID instead.")
  (servoID m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <servo_control-request>) ostream)
  "Serializes a message object of type '<servo_control-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'req))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'req))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'servoID)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <servo_control-request>) istream)
  "Deserializes a message object of type '<servo_control-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'req) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'req) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'servoID)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<servo_control-request>)))
  "Returns string type for a service object of type '<servo_control-request>"
  "control_pkg/servo_controlRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servo_control-request)))
  "Returns string type for a service object of type 'servo_control-request"
  "control_pkg/servo_controlRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<servo_control-request>)))
  "Returns md5sum for a message object of type '<servo_control-request>"
  "e95109d072a249ed2c81c45a1a6b292a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'servo_control-request)))
  "Returns md5sum for a message object of type 'servo_control-request"
  "e95109d072a249ed2c81c45a1a6b292a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<servo_control-request>)))
  "Returns full string definition for message of type '<servo_control-request>"
  (cl:format cl:nil "string req~%uint8 servoID~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'servo_control-request)))
  "Returns full string definition for message of type 'servo_control-request"
  (cl:format cl:nil "string req~%uint8 servoID~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <servo_control-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'req))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <servo_control-request>))
  "Converts a ROS message object to a list"
  (cl:list 'servo_control-request
    (cl:cons ':req (req msg))
    (cl:cons ':servoID (servoID msg))
))
;//! \htmlinclude servo_control-response.msg.html

(cl:defclass <servo_control-response> (roslisp-msg-protocol:ros-message)
  ((angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass servo_control-response (<servo_control-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <servo_control-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'servo_control-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_pkg-srv:<servo_control-response> is deprecated: use control_pkg-srv:servo_control-response instead.")))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <servo_control-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_pkg-srv:angle-val is deprecated.  Use control_pkg-srv:angle instead.")
  (angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <servo_control-response>) ostream)
  "Serializes a message object of type '<servo_control-response>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <servo_control-response>) istream)
  "Deserializes a message object of type '<servo_control-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<servo_control-response>)))
  "Returns string type for a service object of type '<servo_control-response>"
  "control_pkg/servo_controlResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servo_control-response)))
  "Returns string type for a service object of type 'servo_control-response"
  "control_pkg/servo_controlResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<servo_control-response>)))
  "Returns md5sum for a message object of type '<servo_control-response>"
  "e95109d072a249ed2c81c45a1a6b292a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'servo_control-response)))
  "Returns md5sum for a message object of type 'servo_control-response"
  "e95109d072a249ed2c81c45a1a6b292a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<servo_control-response>)))
  "Returns full string definition for message of type '<servo_control-response>"
  (cl:format cl:nil "float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'servo_control-response)))
  "Returns full string definition for message of type 'servo_control-response"
  (cl:format cl:nil "float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <servo_control-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <servo_control-response>))
  "Converts a ROS message object to a list"
  (cl:list 'servo_control-response
    (cl:cons ':angle (angle msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'servo_control)))
  'servo_control-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'servo_control)))
  'servo_control-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servo_control)))
  "Returns string type for a service object of type '<servo_control>"
  "control_pkg/servo_control")