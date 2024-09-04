extends Area2D

signal hit

@export var speed = 400
var screen_size

func _ready() -> void:
	screen_size = get_viewport_rect().size

func _process(delta: float) -> void:
	var v=Input.get_vector("ui_left", "ui_right", "ui_up", "ui_down")
	if v.length() > 0:
		rotation=v.angle()+PI/2
		$AnimatedSprite2D.play()
	else:
		$AnimatedSprite2D.stop()
	#if v.x != 0:
		#$AnimatedSprite2D.animation = "walk"
		#$AnimatedSprite2D.flip_v = false
		#$AnimatedSprite2D.flip_h = v.x < 0
	#elif v.y != 0:
		#$AnimatedSprite2D.animation = "up"
		#$AnimatedSprite2D.flip_v = v.y > 0
	var s=v.length_squared()/4
	Input.start_joy_vibration(0,s,s,delta)
	position += v * speed * delta
	position = position.clamp(Vector2.ZERO, screen_size)

func start(pos):
	position = pos
	show()
	$CollisionShape2D.disabled = false

func _on_body_entered(body: Node2D) -> void:
	hide()
	hit.emit()
	$CollisionShape2D.set_deferred("disabled",true)
