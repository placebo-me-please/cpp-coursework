.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge17 - Debug ]----------"
	@cd "Challenge17" && "$(MAKE)" -f  "Challenge17.mk"
clean:
	@echo "----------Cleaning project:[ Challenge17 - Debug ]----------"
	@cd "Challenge17" && "$(MAKE)" -f  "Challenge17.mk" clean
