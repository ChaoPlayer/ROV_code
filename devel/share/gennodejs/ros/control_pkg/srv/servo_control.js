// Auto-generated. Do not edit!

// (in-package control_pkg.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class servo_controlRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.req = null;
      this.servoID = null;
    }
    else {
      if (initObj.hasOwnProperty('req')) {
        this.req = initObj.req
      }
      else {
        this.req = '';
      }
      if (initObj.hasOwnProperty('servoID')) {
        this.servoID = initObj.servoID
      }
      else {
        this.servoID = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type servo_controlRequest
    // Serialize message field [req]
    bufferOffset = _serializer.string(obj.req, buffer, bufferOffset);
    // Serialize message field [servoID]
    bufferOffset = _serializer.uint8(obj.servoID, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type servo_controlRequest
    let len;
    let data = new servo_controlRequest(null);
    // Deserialize message field [req]
    data.req = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [servoID]
    data.servoID = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.req);
    return length + 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'control_pkg/servo_controlRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f0eacf72d9549eb4f746bd299724faa1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string req
    uint8 servoID
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new servo_controlRequest(null);
    if (msg.req !== undefined) {
      resolved.req = msg.req;
    }
    else {
      resolved.req = ''
    }

    if (msg.servoID !== undefined) {
      resolved.servoID = msg.servoID;
    }
    else {
      resolved.servoID = 0
    }

    return resolved;
    }
};

class servo_controlResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.angle = null;
    }
    else {
      if (initObj.hasOwnProperty('angle')) {
        this.angle = initObj.angle
      }
      else {
        this.angle = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type servo_controlResponse
    // Serialize message field [angle]
    bufferOffset = _serializer.float32(obj.angle, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type servo_controlResponse
    let len;
    let data = new servo_controlResponse(null);
    // Deserialize message field [angle]
    data.angle = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'control_pkg/servo_controlResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2d11dcdbe5a6f73dd324353dc52315ab';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 angle
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new servo_controlResponse(null);
    if (msg.angle !== undefined) {
      resolved.angle = msg.angle;
    }
    else {
      resolved.angle = 0.0
    }

    return resolved;
    }
};

module.exports = {
  Request: servo_controlRequest,
  Response: servo_controlResponse,
  md5sum() { return 'e95109d072a249ed2c81c45a1a6b292a'; },
  datatype() { return 'control_pkg/servo_control'; }
};
