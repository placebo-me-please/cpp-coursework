.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge14A - Debug ]----------"
	@cd "Challenge14A" && "$(MAKE)" -f  "Challenge14A.mk"
clean:
	@echo "----------Cleaning project:[ Challenge14A - Debug ]----------"
	@cd "Challenge14A" && "$(MAKE)" -f  "Challenge14A.mk" clean
