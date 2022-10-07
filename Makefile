.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge19C - Debug ]----------"
	@cd "Challenge19C" && "$(MAKE)" -f  "Challenge19C.mk"
clean:
	@echo "----------Cleaning project:[ Challenge19C - Debug ]----------"
	@cd "Challenge19C" && "$(MAKE)" -f  "Challenge19C.mk" clean
